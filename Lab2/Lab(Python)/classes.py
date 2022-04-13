# Класс для збереження конкретної інформації про абітурієнтів
class Person:

    def __init__(self, full_name, birth, sex):
        self.full_name = full_name
        self.date_of_birth = birth
        self.sex = sex