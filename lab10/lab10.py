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
    print(get_response("generate a Python function for me that output the factorial of the input n."))
    
        
    
    
