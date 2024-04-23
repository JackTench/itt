import requests

# Get dictionary.
dict_url = "https://www.mit.edu/~ecprice/wordlist.10000"
response = requests.get(dict_url)
if response.status_code != 200:
    raise Exception("Failed to fetch dictionary.")
words = response.text.splitlines()

# Create C++ header file.
cpp_header_content = "#ifndef DICTIONARY_H\n#define DICTIONARY_H\n\n"
cpp_header_content += '#include <vector>\n#include<string>\n\n'
cpp_header_content += "namespace Dictionary {\n"
cpp_header_content += "    const std::vector<std::string> dictionary = {\n"
cpp_header_content += ",\n".join(['        "' + word + '"' for word in words])
cpp_header_content += "\n    };\n}\n\n#endif\n"

# Write.
with open("dictionary.h", "w") as file:
    file.write(cpp_header_content)