import speech_recognition as sr
import pyttsx3
import webbrowser
from datetime import datetime
import wikipedia
import pywhatkit
import calendar  

def listen():
    recognizer = sr.Recognizer()
    with sr.Microphone() as scr:
        print("Listening ....")
        recognizer.adjust_for_ambient_noise(scr)
        audio = recognizer.listen(scr)
        try:
            command = recognizer.recognize_google(audio, language='en')
            print(f"You said: {command}")
            return command.lower()
        except sr.UnknownValueError:
            print("Sorry, I could not understand your command.")
            return ""
        except sr.RequestError:
            print("Could not request results from Google Speech Recognition service.")
            return ""

def get_time():
    return datetime.now().strftime("%H:%M:%S")

def get_date():
    now = datetime.now()
    month = calendar.month_name[now.month]      
    return f"{now.strftime('%A')} {now.day} {month} {now.year}" 

def respond_with_voice(response):
    engine = pyttsx3.init()
    
    # Slowing down the speech rate
    rate = engine.getProperty('rate')   # Getting current speech rate
    engine.setProperty('rate', rate - 60) # Reducing the rate by 50 units

    engine.say(response)
    engine.runAndWait()

def greet_user():
    current_time = datetime.now().strftime("%H")
    if current_time < "12":
        response = "Good morning Mohamed"
    elif current_time < "18":
        response = "Good afternoon Mohamed"
    else:
        response = "Good evening Mohamed"
    
    print(response)
    respond_with_voice(response)

def main():
    greet_user() 

    while True:
        command = listen()

        if 'time' in command:
            current_time = get_time()
            response = f"The current time is {current_time}."
            print(response)
            respond_with_voice(response)

        elif 'google' in command:
            webbrowser.open("https://www.google.com")
            response = "Opening Google."
            print(response)
            respond_with_voice(response)

        elif 'exit' in command or 'turn off' in command:
            print("Exiting the system.")
            respond_with_voice("Exiting the system.")
            break
        
        elif 'date' in command:
            current_date = get_date()
            response = f"The current date is {current_date}."
            print(response)
            respond_with_voice(response)
        
        elif 'tell me ' in command:
            search_query = command.replace('tell me ', '')
            try:
                response = wikipedia.summary(search_query, sentences=1)
            except wikipedia.exceptions.DisambiguationError as e:
                response = f"Multiple options found. {str(e)}"
            except wikipedia.exceptions.PageError as e:
                response = f"No information found. {str(e)}"
            print(response)
            respond_with_voice(response)
        
        elif 'play' in command or 'sing' in command:
            song_name = command.replace('play', '').replace('sing', '')
            try:
                pywhatkit.playonyt(song_name)
                response = f"Playing {song_name} on YouTube."
            except Exception as e:
                response = f"Failed to play {song_name}: {str(e)}"
            print(response)
            respond_with_voice(response)
        
        else:
            response = "I did not understand that command."
            print(response)
            respond_with_voice(response)

if __name__ == "__main__":
    main()
