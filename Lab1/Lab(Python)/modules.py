# Create new text for input.txt
def create_input_text():
    text = []
    flag = True
    print("Enter text (Press double Enter if u wanna end text)")
    while flag:
        temp = input()
        if temp == '':
            flag = False
        else:
            text.append(temp)
    return text


# Read and print txt file
def read_txt_file(name_of_file):
    print(f"\nYour {name_of_file} ->")
    with open(name_of_file, 'r') as file_txt:
        for line in file_txt:
            print(line, end='')


# Create output.txt
def create_file(name_of_file, content):
    with open(name_of_file, 'w+') as file:
        for i in range(0, len(content)):
            file.write(content[i])
            if i != len(content)-1:
                file.write('\n')


# Create new content of output.txt
def create_new_content(content):
    new_content = []

    chars_dict = {'comma': 0, 'point': 0, 'space': 0, 'words': 0}
    chars_string = "\nComma has been deleted {comma} times." \
                   "\nSpace has been deleted {space} times." \
                   "\nPoint has been deleted {point} times." \
                   "\nWords have been deleted {words} times."

    for string in content:
        new_string, chars_dict = delete_specific_chars(string, chars_dict)
        new_string, chars_dict = delete_words(new_string, chars_dict)
        new_content.append(new_string)
    new_content.append(chars_string.format(comma=chars_dict['comma'], space=chars_dict['space'],
                                           point=chars_dict['point'], words=chars_dict['words']))
    return new_content


# Delete specific chars like , . 'space'
def delete_specific_chars(string, chars_dict):
    new_string = ''
    specific_chars = [',', ' ', '.']
    for count in range(0, len(string) - 1):
        if string[count] == string[count + 1] and string[count] in specific_chars:
            if string[count] == ',':
                chars_dict['comma'] += 1
            elif string[count] == '.':
                chars_dict['point'] += 1
            else:
                chars_dict['space'] += 1
        else:
            new_string += string[count]
    new_string += string[-1]
    return new_string, chars_dict


# Delete specific words of content file
def delete_words(string, chars_dict):
    new_string_list = []
    string_list = string.split()
    for word in string_list:
        if len(word) != 1:
            new_string_list.append(word)
        elif not word.isalpha():
            new_string_list.append(word)
        else:
            chars_dict['words'] += 1
    new_string = ' '.join(new_string_list)
    return new_string, chars_dict