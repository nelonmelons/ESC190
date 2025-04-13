from notopenai import NotOpenAI
import json
# Input the API key obtained for the lab
API_KEY = "1GHUU2VlpsEJj74HxXuA"
CLIENT = NotOpenAI(api_key=API_KEY)
def get_response(prompt):
    chat_completion = CLIENT.chat.completions.create(
    messages=[
        {
            "role": "user",
            "content": prompt,
        }
    ],
    model="gpt-3.5-turbo", # the GPT model to use
)
    response_str = chat_completion.choices[0].message.content
    return response_str


if __name__ == "__main__":
    s = '''Date,Character,Age,HeightCm,AppleCount,MoodRating
    2025-01-15,Snow White,14,157.5,1,8.5
    Doc,200,91.4,3,7.2
    2025-01-16,Grumpy,199,89.0,0,3.4
    2025-01-16,202,94.0,2,9.7
    2025-01-17,Sleepy,202,90.2,1,6.3
    Bashful,198,88.5,1,5.8
    2025-01-18,Sneezy,197,92.3,2,7.4
    2025-01-18,Dopey,195,87.1,4,8.9
    2025-01-19,,42,175.6,0,2.1
    Prince,25,185.3,2,9.5
    2025-01-20,Huntsman,38,178.4,1,6.7
    2025-01-20,250,92.0,3,7.3
    3
    2025-01-21,Forest Animals,5,30.5,4,9.2'''
    
    string = get_response('''Parse this CSV string using a python script. the Result needs
to be a dictionary of dictionaries. return ONLY the python script. do not include any comments or ```python. \n\n\n''' + s)
    #print(string)
    exec(string)
    
        
    
    