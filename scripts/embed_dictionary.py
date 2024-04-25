import requests

# Get dictionary from the web.
dict_url = "https://www.mit.edu/~ecprice/wordlist.10000"
response = requests.get(dict_url)
if response.status_code != 200:
    raise Exception("Failed to fetch dictionary.")
words = response.text.splitlines()

# Create C files.
c_header = "#ifndef DICTIONARY_H\n#define DICTIONARY_H\n\n"
c_header += "#include <stdlib.h>\n#include <string.h>\n\n"
c_header += "extern const char *const dictionary[];\n\n"
c_header += "const char *const dictionary[] = {\n"
c_header += ",\n".join(['    "' + word + '"' for word in words])
c_header += "\n};\n#endif"

# Write to file.
with open("../src/dictionary.h", "w") as file:
    file.write(c_header)