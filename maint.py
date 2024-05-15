import hashlib
import threading
import time
import random

class ChordClient:
    def __init__(self, port_number=5000):
        self.port_number = port_number
        self.node_id = hashlib.sha1(str((self.port_number)).encode()).hexdigest()[:40]
        self.ip_address = "127.0.0.1"   
        self.finger_table = [None] * 161  # initialise finger table with None
        self.successor_list = []
        self.predecessor = None

        # multithreading for stabilization routines
        self.stabilization_thread = threading.Thread(target=self.periodic_stabilization)
        self.stabilization_thread.daemon = True
        self.stabilization_thread.start()
        pass

    def periodic_stabilization(self):
        while True:
            self.stabilize()
            self.fix_fingers()
            self.check_predecessor()
            time.sleep(0.5)  # timely invoke stabilization routines every 500 ms
    
    def port(self, port_number=None):
        if port_number is not None:
            #settting the port number 
            self.port_number = port_number
            self.node_id = hashlib.sha1(str((self.port_number)).encode()).hexdigest()[:40]
        else:
            # printing the current poirt num
            print(f" Current port number : {self.port_number}")
        pass

    def create(self):
        self.finger_table[1] = self
        self.successor_list.append(self)

        pass
    
    def update_finger_table(self, ip , port):
        # calculating node id for the new node

        new_node_id = hashlib.sha1(str(port).encode()).hexdigest()[:40]

        # finding the node on first finger which is greater than new node

        for i in range (1, len(self.finger_table)):
            finger_start = (self.node_id + 2** (i-1) % (2**160))

            if finger_start > new_node_id:
                self.finger_table[i] = (ip,port)
                break
            
        if all(entry is None for entry in self.finger_table[1:]):
            self.finger_table[1] = (ip,port)

        pass


    def join(self, ip, port):
        # Send a request to join the DHT
        # fucntion 'to join request' to main dht node
        response = send_request(ip,port,"join request",self.node_id)

        if response == "success":
            self.update_finger_table(ip,port)
            self.update_succcessor_list(ip,port)
            print("joined the dht successfully")
        else:
            print("Failed to join the dht")
        pass


    def send_request(ip, port, request_type, data):
    # Simulate sending a request to join the DHT
        print(f"Sending {request_type} request to {ip}:{port} with data: {data}")

 
        response = random.choice(["success", "failure"])
        return response
       

    def put(self, key, value):
        # Put the key-value pair in the DHT
        successor = self.find_successor(hashlib.sha1(str(key).encode()).hexdigest())
        successor.put_locally(key, value)
        print(f"Key '{key}' with value '{value}' stored in the DHT.")

    def put_locally(self, key, value):
        # Store the key-value pair locally
        self.data[key] = value

    def printstate(self):
        # Print the local state information
        print("Local state information:")
        print(f"Node ID: {self.node_id}")
        print(f"IP address: {self.ip_address}")
        print(f"Port number: {self.port_number}")
        print("Finger table:")
        for i, finger_entry in enumerate(self.finger_table):
            if finger_entry:
                print(f"  Finger {i}: {finger_entry}")
            else:
                print(f"  Finger {i}: None")
        print("Successor list:")
        for i, successor in enumerate(self.successor_list):
            print(f"  Successor {i+1}: {successor}")
        print(f"Predecessor: {self.predecessor}")
        pass

    def closest_preceding_node(self, key):
        # find the closest preceding node
        for i in range(len(self.finger_table) - 1, 0, -1):
            if self.finger_table[i] and self.finger_table[i].node_id < key:
                return self.finger_table[i]
        return None

    def find_successor(self, key):
        # fiund the successor of the given key
        # If there are no successors, return None
        if not self.successor_list:
            # print("No successors found. Unable to find successor.")
            return None
        
        # If the key's hash falls between the current node and its successor, return the successor
        if self.predecessor and self.node_id < key <= self.successor_list[0].node_id:
            return self.successor_list[0]

        # else, forward the request to the closest preceding node
        else:
            closest_preceding_node = self.closest_preceding_node(key)
            if closest_preceding_node:
                # Forward request recursively
                return closest_preceding_node.find_successor(key)
            else:
                # If no closest preceding node found, return the current node's successor
                return self.successor_list[0]

    def update_predecessor(self, predecessor):
        # simply update the predevessor 
        self.predecessor = predecessor

    def update_successor(self, successor):
        # Assuming successor is a tuple (ip_address, port_number)
        self.successor_list[0] = successor

    def update_finger_tables_on_leave(self):
        
        # Iterate through the finger table entries of other nodes and update them if necessary

        for node in self.successor_list:
            # the finger table of each node is stored as a list of tuples (ip_address, port_number)

            for i in range(1, len(node.finger_table)):
                # If the successor of the node is the leaving node, update it with the next successor
                if node.finger_table[i] == (self.ip_address, self.port_number):
                    node.finger_table[i] = self.successor_list[0]

    def leave(self):
        # Leave the network

        # transfer data
        for key, value in self.data.items():
            successor = self.find_successor(key)
            successor.put(key, value)

        # inform successor/s about departture
        for successor in self.successor_list:
            successor.update_predecessor(self.predecessor)

        # inform predecessor about departtrure
        if self.predecessor:
            self.predecessor.update_successor(self.successor_list[0])

        
        # remove node from successor list of predecessor
        if self.predecessor:
            self.predecessor.successor_list.remove((self.ip_address, self.port_number)) 


        # update other nodes finger tables if necessary
        self.update_finger_tables_on_leave()
        pass

    def stabilize(self):
        # Get the successor's predecessor
        if self.successor_list:  # Check if the successor list is not empty
        # Get the successor's predecessor
            successor_predecessor = self.successor_list[0].predecessor   
            
            # if the successor's predecessor is between this node and its successor, update this node's successor 
            if successor_predecessor and self.node_id < successor_predecessor.node_id < self.successor_list[0].node_id:
                self.successor_list[0] = successor_predecessor
            
            # Notify the new successor 
            self.successor_list[0].notify(self)
        # else:
            # print("Successor list is empty. Unable to stabilize.")
    
    def notify(self, predecessor_node):
        # Update the predecessor
        if self.predecessor is None or (predecessor_node.node_id > self.predecessor.node_id):
            self.predecessor = predecessor_node

    def fix_fingers(self):
        # Refresh finger-table entries periodically using multithreading 
        for i in range(1, 161):# iterate over finger table 
            # Calculate the ith finger
            finger_id = (int(self.node_id, 16) + (2 ** (i - 1))) % (2 ** 160)
            finger_node = self.find_successor(finger_id)
            self.finger_table[i] = finger_node

    def check_predecessor(self):
        # Check the status of the predecessor node
        if self.predecessor is not None:
            # Placeholder for logic to check the status of the predecessor node
            pass
        # else:
        #     print("No predecessor node set.")

    def handle_command(self, command):
        # Handle  
        if command.lower() == "printstate":
            self.printstate()
        elif command.lower().startswith("put"):
            parts = command.split(" ", 2)
            if len(parts) != 3:
                print("Invalid 'put' command format. Use: put <key> <value>")
            else:
                key = parts[1]
                value = parts[2]
                self.put(key, value)
        elif command.lower().startswith("get"):
            parts = command.split(" ", 1)
            if len(parts) != 2:
                print("Invalid 'get' command format. Use: get <key>")
            else:
                key = parts[1]
                self.get(key)
        elif command.lower().startswith("join"):
            parts = command.split(" ", 2)
            if len(parts) != 3:
                print("Invalid 'join' command format. Use: join <ip> <port>")
            else:
                ip = parts[1]
                port = int(parts[2])
                self.join(ip, port)
        elif command.lower() == "leave":
            self.leave()
        elif command.lower() == "exit":
            print("Exiting...")
            exit()
        else:
            print("Unknown command. Available commands: printstate, put, get, join, leave, exit")

    def get(self, key):
        # Get the value for the given key
        if key in self.data:
            print(f"Value for key '{key}': {self.data[key]}")
            return self.data[key]
        else:
            print(f"No value found for key '{key}'")
            return None



if __name__ == "__main__":
    chord_client = ChordClient()

    while True:
        command = input("> ")
        if not command:
            continue
        chord_client.handle_command(command)
