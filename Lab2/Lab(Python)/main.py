import modules as md

# Назва файлів
input = "input.bin"
output = "output.bin"

# Створення інформації про абітурієнтів
persons_base = md.create_person_base()

# Запис контенту та зчитування вхідного бінарного файлу
md.write_file(input, persons_base)
md.read_file(input)

# Зміна інформації з абітурієнтами
modified_persons_base = md.modify_data(persons_base)

# Запис контенту та зчитування вихідного бінарного файлу
md.write_file(output, modified_persons_base)
md.read_file(output)
