import classes
from datetime import datetime


# Створення дати про абітурієнтів
def create_person_base():
    data = []
    count = int(input("How many persons do u wanna enter? "))

    for i in range(count):
        full_name = input("Enter full name of person: ")
        date_of_birth = input("Enter Date of Birth of person: ")
        sex = input("Enter Sex of ur person: ")

        data.append(classes.Person(full_name, date_of_birth, sex))

    return data


# Створення бінарного файлу та запис дати
def write_file(name_of_file, content):
    with open(name_of_file, "wb") as file:
        for i in range(len(content)):
            bt = (content[i].full_name + ',' + content[i].date_of_birth + ',' + content[i].sex).encode()
            if i != len(content)-1:
                bt += '\n'.encode()
            file.write(bt)


# Зчитування бінарного файлу
def read_file(name_of_file):
    print("\n" + name_of_file + " file: ")
    with open(name_of_file, "rb") as file:
        for line in file:
            s = line.decode()
            if s[-1] == '\n':
                s = s[:-1]
            print(s)


# Зміна контенту
def modify_data(content):
    now = datetime.now()
    current_time = [now.day, now.month, now.year]
    modify_content = []

    print("\nPersons that older than 35 yd: ")
    for person in content:
        date_of_birth = birth_transform(person.date_of_birth)
        year = current_time[2] - date_of_birth[2]

        if current_time[1] < date_of_birth[1] or \
                (current_time[1] == date_of_birth[1] and current_time[0] < date_of_birth[0]):
            year -= 1

        if 18 <= year <= 27 and person.sex == "чоловік":
            modify_content.append(person)
        elif year > 35:
            print(person.full_name, person.date_of_birth, person.sex)

    return modify_content


# Переведення строки з датою народження в вектор з цілими числами
def birth_transform(date):
    date_of_birth = []
    date_of_birth_string_list = date.split('.')
    for j in range(0, 3):
        date_of_birth.append(int(date_of_birth_string_list[j]))

    return date_of_birth