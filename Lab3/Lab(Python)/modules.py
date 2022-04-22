import classes


# Create a list with objects that contents about classes "Third Dimensional Vector"
def create_list_with_classes():
    list_with_objects = []
    count = int(input("How many vectors do u wanna create? "))

    for i in range(0, count):
        print("Enter vector {num} values:".format(num=(i+1)))
        vector = classes.ThirdDimensionalVector
        x_values = int(input("Enter x: "))
        y_values = int(input("Enter y: "))
        z_values = int(input("Enter z: "))
        list_with_objects.append(vector(x_values, y_values, z_values))

    return list_with_objects


# Output values of objects_list
def output_list_with_classes(list_with_objects):
    print("\nOutput vectors")

    for i in range(0, len(list_with_objects)):
        print("Vector {num} values:".format(num=(i + 1)))
        print(list_with_objects[i].get_values())


# Create a list with length
def create_list_with_lengths(list_with_objects):
    list_with_length = []

    for object_variable in list_with_objects:
        list_with_length.append(object_variable.get_length())

    return list_with_length


# Output list with values
def output_values(list):
    for i in range(0, len(list)):
        print("Vector {num} length value: {length}".format(num=(i + 1), length=list[i]))


# Find the biggest length value through length list
def find_biggest(list_lengths):
    max_value = list_lengths[0]

    for value in list_lengths:
        if value > max_value:
            max_value = value

    print("\nThe biggest length value has vector with: ", max_value)