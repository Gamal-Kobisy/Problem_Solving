import os
import shutil
import re

def organize_files(directory):
    # Dictionary mapping URL keywords to folder names
    # Note: 'gym' is checked first to separate it from standard Codeforces
    oj_mapping = {
        "codeforces.com/gym": "Gym",
        "codeforces.com": "Codeforces",
        "atcoder.jp": "AtCoder",
        "cses.fi": "CSES",
        "vjudge.net": "Vjudge",
        "spoj.com": "SPOJ",
        "uva.onlinejudge.org": "UVA",
        "onlinejudge.org": "UVA" # Catch alternative UVA link
    }
    
    not_famous_folder = "Not Famous Online Judges"
    no_link_folder = "Uncategorized" # For files without any links

    # Loop through all files in the directory
    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)

        # Skip directories and the script itself
        if os.path.isdir(file_path) or filename == "organize.py":
            continue

        try:
            # Read file content safely, ignoring character encoding errors
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()

            # Search for URLs in the text
            urls = re.findall(r'https?://[^\s]+', content)

            target_folder = None

            if urls:
                url = urls[0].lower() # Assume the first link is the problem link
                
                # Check if the URL belongs to a known OJ
                for keyword, folder_name in oj_mapping.items():
                    if keyword in url:
                        target_folder = folder_name
                        break
                
                # If a link was found but didn't match the famous ones
                if target_folder is None:
                    target_folder = not_famous_folder
            else:
                # No link found in the file
                target_folder = no_link_folder

            # Create the folder if it doesn't exist
            folder_path = os.path.join(directory, target_folder)
            if not os.path.exists(folder_path):
                os.makedirs(folder_path)

            # Move the file to the target folder
            new_file_path = os.path.join(folder_path, filename)
            shutil.move(file_path, new_file_path)
            
            print(f"Moved: '{filename}' -> '{target_folder}/'")

        except Exception as e:
            print(f"Error processing {filename}: {e}")

if __name__ == "__main__":
    # Runs the function in the current directory
    current_directory = os.path.dirname(os.path.abspath(__file__))
    print(f"Organizing files in: {current_directory}\n{'-'*40}")
    organize_files(current_directory)
    print(f"{'-'*40}\nOrganization complete!")