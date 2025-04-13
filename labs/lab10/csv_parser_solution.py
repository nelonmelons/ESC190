from p5 import get_response

def test_different_prompts():
    """Test different prompts to see which ones work best for parsing the CSV data."""
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
    
    # A prompt that provides detailed instructions on handling missing values
    detailed_prompt = """
Parse this CSV string using Python. The result should be a dictionary of dictionaries where:
1. Each row becomes an entry in the dictionary
2. The key for each entry should be a unique identifier (combination of date + character name)
3. IMPORTANT: Some rows are missing dates or character names
   - If a date is missing, use the most recent valid date
   - If a character name is missing but there's a numeric value in that position, it's actually the Age column
   - If a character name is missing completely, use "Unknown" as the name
4. Some rows might be corrupted (like the row with just "3") - these should be skipped
5. Parse numeric values as numbers (float or int as appropriate)
6. Return a clean dictionary of dictionaries

Here's the CSV data:
"""
    
    # A prompt that provides example code structure
    code_example_prompt = """
I need Python code to parse this CSV string that has data formatting issues. The code should:
1. Handle missing dates (use most recent date)
2. Handle missing character names (use "Unknown")
3. Handle shifted columns when character name is missing but age is present
4. Skip corrupted rows (like a row with just a single value)
5. Parse numeric values properly

For example, a structure like:
```python
def parse_csv(csv_string):
    # Split into lines
    lines = csv_string.strip().split('\\n')
    
    # Get headers
    headers = [h.strip() for h in lines[0].split(',')]
    
    result = {}
    current_date = None
    
    # Process each data row
    for line in lines[1:]:
        # Your parsing logic here
        # Handle missing dates with current_date
        # Handle missing character names
        # Create dictionary entry
    
    return result
```

Write complete code to parse this CSV:
"""
    
    # Test the prompts (uncomment to test)
    # print("\n\n=== DETAILED PROMPT RESULT ===\n")
    # print(get_response(detailed_prompt + s))
    
    # print("\n\n=== CODE EXAMPLE PROMPT RESULT ===\n")
    # print(get_response(code_example_prompt + s))

def our_csv_parser(csv_string):
    """
    Parse a CSV string with missing values into a dictionary of dictionaries.
    
    This function handles:
    - Missing dates (uses previous date)
    - Missing character names 
    - Shifted columns when character name is missing
    - Corrupted rows
    """
    lines = csv_string.strip().split('\n')
    headers = [h.strip() for h in lines[0].split(',')]
    
    result = {}
    current_date = None
    
    for line in lines[1:]:
        # Skip empty lines
        if not line.strip():
            continue
            
        # Skip clearly corrupted lines (too few values)
        values = [v.strip() for v in line.split(',')]
        if len(values) <= 1:
            continue
            
        # Determine if this row starts with a date
        has_date = values[0] and values[0].startswith('202')
        
        if has_date:
            current_date = values[0]
            char_name = values[1] if values[1] else "Unknown"
            data_values = values[2:] if len(values) > 2 else []
            start_idx = 2
        else:
            # No date - use the fields differently
            # Check if first field is a number (age) or character name
            if values[0].replace('.', '', 1).isdigit():
                # First field is a number (likely Age), so no character name
                char_name = "Unknown"
                data_values = values
                start_idx = 0
            else:
                # First field is character name
                char_name = values[0]
                data_values = values[1:] if len(values) > 1 else []
                start_idx = 1
                
        # Skip if we still don't have a date
        if not current_date:
            continue
            
        # Create entry ID
        entry_id = f"{current_date}_{char_name}"
        
        # Create dictionary for this entry
        entry = {'Date': current_date, 'Character': char_name}
        
        # Add remaining data with appropriate types
        for i, value in enumerate(data_values):
            if i + start_idx >= len(headers):
                break
                
            header = headers[i + start_idx]
            
            # Convert to appropriate type
            if value:
                if header in ['Age', 'AppleCount']:
                    # Integer values
                    try:
                        entry[header] = int(float(value))
                    except ValueError:
                        entry[header] = value
                elif header in ['HeightCm', 'MoodRating']:
                    # Float values
                    try:
                        entry[header] = float(value)
                    except ValueError:
                        entry[header] = value
                else:
                    entry[header] = value
            else:
                entry[header] = None
                
        result[entry_id] = entry
    
    return result

def test_our_parser():
    """Test our CSV parser with the problematic data."""
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
    
    result = our_csv_parser(s)
    
    # Print the parsed result
    import json
    print(json.dumps(result, indent=2))
    
    # Verify some known values
    assert result["2025-01-15_Snow White"]["Age"] == 14
    assert result["2025-01-15_Doc"]["AppleCount"] == 3
    assert result["2025-01-16_Unknown"]["HeightCm"] == 94.0
    assert result["2025-01-19_Unknown"]["Age"] == 42
    assert result["2025-01-19_Prince"]["Age"] == 25
    assert result["2025-01-20_Unknown"]["Age"] == 250
    assert "3" not in result  # The corrupted line should be skipped
    
    print("All tests passed!")

def create_better_prompt():
    """Create a prompt that reliably gets GPT-3.5 to solve the problem."""
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
    
    optimal_prompt = """
I need Python code to carefully parse this CSV string that has several data formatting issues.

SPECIFIC ISSUES TO HANDLE:
1. Missing dates: When a row doesn't start with a date, use the most recent valid date from previous rows
2. Missing character names: When the character name is missing, use "Unknown" as the name
3. Column shifting: Some rows that are missing dates have their fields shifted left. You need to detect this and parse accordingly
4. Invalid rows: There's at least one row with just a single value (the number "3") - skip these rows
5. Type conversion: Convert numeric fields to appropriate types (int or float)

Write code that can parse this CSV into a dictionary of dictionaries where:
- Dictionary keys should be a unique identifier combining date and character name
- Each row's data should become an inner dictionary with all fields

Return the complete Python code and show the result when run on this data.

CSV data:
"""
    
    response = get_response(optimal_prompt + s)
    print(response)
    
    # Let's see if the code works
    try:
        # Be careful with exec, but in this controlled environment it's okay
        namespace = {}
        exec(response, namespace)
        # If we're here, the code executed - let's see if it produced a result
        if 'result' in namespace:
            print("\nVerification of GPT's solution:")
            result = namespace['result']
            # Check if any keys exist
            if result:
                print(f"Success! Generated code parsed {len(result)} entries.")
                return True
        print("Code executed but didn't produce expected results")
        return False
    except Exception as e:
        print(f"Generated code failed to run: {e}")
        return False

if __name__ == "__main__":
    # Uncomment to test different prompts
    # test_different_prompts()
    
    # Test our parser
    print("\n===== TESTING OUR PARSER =====\n")
    test_our_parser()
    
    # Test creating a better prompt
    print("\n===== TESTING BETTER PROMPT =====\n")
    create_better_prompt() 