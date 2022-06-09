from classes import TDate, TTime
import random


# Create a container with objects
def create_lists_with_objects():
    objects_list = []
    time_count = int(input("How many time objects do u wanna create? "))
    date_count = int(input("How many date objects do u wanna create? "))
    for i in range(0, time_count):
        value1, value2 = [random.randint(0, 60) for i in range(0, 2)]
        value3 = random.randint(0, 24)
        objects_list.append(TTime(value1, value2, value3))
    for i in range(0, date_count):
        value1 = random.randint(1, 31)
        value2 = random.randint(1, 12)
        value3 = random.randint(1, 2022)
        objects_list.append(TDate(value1, value2, value3))

    return objects_list


def find_correct_dates_and_time(list_with_objects):
    correct_objects = []
    for t_object in list_with_objects:
        if isinstance(t_object, TDate):
            values = t_object.get_values()
            if values[0] < 60 and values[1] < 60 and values[2] < 24:
                correct_objects.append(t_object)
    return correct_objects


def output_objects(objects):
    for t_object in objects:
        print(t_object)


def change_list(objects, correct_objects):
    new_objects = []
    for t_object in objects:
        if t_object not in correct_objects:
            if isinstance(t_object, TTime):
                t_object.add_value(15, 2)
            else:
                t_object.min_value(5, 1)

        new_objects.append(t_object)
    return new_objects