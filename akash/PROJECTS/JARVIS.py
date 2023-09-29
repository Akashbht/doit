import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices[0].id)
engine.setProperty('voice',voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour <12 :
        speak('Good Morning!')

    elif hour >= 12 and hour <18:
        speak('Good Afternoon!')

    else:
        speak('Good Evening!')

    speak('I am Jarvis. Please tell me how may i help you')

def takeCommand():

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening...')
        r.pause_threshold = 1
        audio = r.listen(source)

    try :
        print('Recognising...')
        query = r.recognize_google(audio,language='eng in')
        print('User said, ', query)

    except Exception as e:
        print(e)
        print('Say that again please...')
        return "None"

    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('aakshbht@gmail.com','Inc0rrect')
    server.sendmail('aakshbht@gmail.com', to, content)
    server.close()


if __name__ == '__main__':
    wishMe()
    # while True:
    if 1:
        query = takeCommand().lower()



        if 'wikipedia' in query:
            speak('Searching wikipedia...')
            query = query.replace('wikipedia'," ")
            results = wikipedia.summary(query, sentences= 2)
            speak('According to wikipedia...')
            print(results)
            speak(results)
        elif 'open youtube' in query:
            webbrowser.open('youtube.com')
        elif 'open google' in query:
            webbrowser.open('google.com')
        elif 'open stackoverflow' in query:
            webbrowser.open('stackoverflow.com')


        elif 'play music' in query:
            music_dir = 'D:\\Music\\Best Hindi'
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir, songs[0]))

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime('%H:%M:%S')
            print(str(strTime))
            speak("Sir, The time is", strTime)

        elif 'open photoshop' in query:
            path = "C:\\Program Files\\Adobe\\Adobe Photoshop CC 2019\\Photoshop.exe"
            os.startfile(path)

        elif 'open code' in query:
            path = "C:\\Program Files\\JetBrains\\PyCharm 2020.1\\bin\\pycharm64.exe"
            os.startfile(path)

        elif 'email to akash' in query:
            try:
                speak('What should i say..')
                content = takeCommand()
                to = "aakshbht@gmail.com"
                sendEmail(to, content)
                speak('Email has been sent.')
            except Exception as e:
                print(e)
                speak('sorry, i am not able to send this email.')


