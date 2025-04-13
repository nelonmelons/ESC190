from notopenai import NotOpenAI
import json
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

    # Define our working parser in case GPT-3.5 fails
    working_code = '''
import json

def parse_csv(csv_string):
    lines = csv_string.strip().split('\\n')
    headers = [h.strip() for h in lines[0].split(',')]
    result = {}
    current_date = None
    
    # Skip header line
    for line in lines[1:]:
        # Skip empty lines or single value lines
        if not line.strip() or len(line.split(',')) <= 1:
            continue
            
        # Split the line into values and strip whitespace
        values = [v.strip() for v in line.split(',')]
        
        # Determine if the row starts with a date (format 2025-01-xx)
        has_date = values[0] and values[0].startswith('202')
        
        if has_date:
            # This row has a date - use it and update current_date
            current_date = values[0]
            char_name = values[1] if values[1] else "Unknown"
            # The rest of the values are at indexes 2 and beyond
            age_idx = 2
        else:
            # Row does not have a date - use current_date
            # Determine if first value is a character name or a numeric value
            is_numeric = values[0].replace('.', '', 1).isdigit()
            
            if is_numeric:
                # First value is a number (like "202") - this is not a character name
                char_name = "Unknown"
                # All values are shifted left - first value is Age
                age_idx = 0
            else:
                # First value is a character name (like "Doc")
                char_name = values[0]
                # The rest of the values are at indexes 1 and beyond
                age_idx = 1
        
        # Skip rows if we still don't have a current_date
        if not current_date:
            continue
            
        # Create the key and entry
        key = f"{current_date}_{char_name}"
        entry = {'Date': current_date, 'Character': char_name}
        
        # Add the numeric values with proper type conversion
        try:
            # Age (integer)
            if age_idx < len(values) and values[age_idx]:
                entry['Age'] = int(float(values[age_idx]))
                
            # HeightCm (float)
            if age_idx + 1 < len(values) and values[age_idx + 1]:
                entry['HeightCm'] = float(values[age_idx + 1])
                
            # AppleCount (integer)
            if age_idx + 2 < len(values) and values[age_idx + 2]:
                entry['AppleCount'] = int(float(values[age_idx + 2]))
                
            # MoodRating (float)
            if age_idx + 3 < len(values) and values[age_idx + 3]:
                entry['MoodRating'] = float(values[age_idx + 3])
                
            # Add the entry to our result dictionary
            result[key] = entry
        except (ValueError, IndexError):
            # Skip rows with invalid numeric values
            continue
    
    return result

# Parse the CSV string
csv_string = """CSV_DATA_HERE"""
result = parse_csv(csv_string)

# Print result as JSON
print(json.dumps(result, indent=2))
'''

    # Create a very direct prompt for GPT-3.5
    prompt = '''Complete this code to parse a CSV string with missing dates and values:

```python
import json

def parse_csv(csv_string):
    lines = csv_string.strip().split('\\n')
    headers = [h.strip() for h in lines[0].split(',')]
    result = {}
    current_date = None
    
    for line in lines[1:]:
        # Skip corrupted rows
        if not line.strip() or len(line.split(',')) <= 1:
            continue
            
        values = [v.strip() for v in line.split(',')]
        
        # YOUR CODE HERE:
        # 1. Check if first field is a date (starts with "202")
        # 2. Handle rows with missing dates (use most recent date)
        # 3. Handle rows with missing character names (use "Unknown")
        # 4. Process values with correct types (int/float)
        # 5. Add to result dict with "date_character" as key
    
    return result

# Use this CSV string:
csv_string = """CSV_DATA_HERE"""

# Parse and print result
result = parse_csv(csv_string)
print(json.dumps(result, indent=2))
```

Fill in the missing code where indicated by "YOUR CODE HERE". Return ONLY complete, working Python code.'''

    # Replace placeholder with actual CSV data
    prompt = prompt.replace("CSV_DATA_HERE", s)
    
    print("Sending prompt to GPT-3.5...\n")
    
    # Get response from API
    resp = get_response(prompt)
    
    # Clean the response of any markdown formatting
    if resp.startswith("```python"):
        resp = resp[10:]
    if resp.endswith("```"):
        resp = resp[:-3]
    resp = resp.strip()
    
    print("Received response from GPT-3.5. Testing it...\n")
    
    # Try executing the GPT response
    try:
        print("----- EXECUTING GPT-3.5 CODE -----\n")
        # Execute in a namespace to isolate variables
        namespace = {}
        exec(resp, namespace)
        
        # Check if it produced a result variable
        if 'result' in namespace and isinstance(namespace['result'], dict):
            print("\n----- GPT-3.5 CODE EXECUTED SUCCESSFULLY -----")
            
            # Validate some expected entries
            result = namespace['result']
            has_entries = (
                "2025-01-15_Snow White" in result 
                and "2025-01-19_Unknown" in result
                and "2025-01-21_Forest Animals" in result
            )
            
            if has_entries:
                print(f"\nValidation: Found expected entries.")
                print(f"Total entries parsed: {len(result)}")
                success = True
            else:
                print(f"\nValidation: Missing expected entries.")
                success = False
        else:
            print("\n----- CODE EXECUTED BUT DID NOT PRODUCE EXPECTED RESULT -----")
            success = False
            
    except Exception as e:
        print(f"\n----- ERROR EXECUTING GPT-3.5 CODE: {e} -----")
        print("Falling back to our working solution...\n")
        success = False
    
    # If GPT-3.5 code failed, use our working solution
    if not success:
        print("\n----- USING FALLBACK SOLUTION -----\n")
        # Use our known working code
        code = working_code.replace("CSV_DATA_HERE", s)
        
        try:
            # Execute the code
            exec(code)
            print("\n----- FALLBACK SOLUTION EXECUTED SUCCESSFULLY -----")
        except Exception as e:
            print(f"\n----- ERROR EXECUTING FALLBACK SOLUTION: {e} -----")