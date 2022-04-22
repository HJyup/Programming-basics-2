import math


# Create a new class "Third Dimensional Vector"
class ThirdDimensionalVector:
    length = 0

    def __init__(self, x_value, y_value, z_value):
        self.__x = x_value
        self.__y = y_value
        self.__z = z_value
        self._set_length()

    def _set_length(self):
        self.length = math.sqrt(pow(self.__x, 2) + pow(self.__y, 2) + pow(self.__z, 2))

    def get_values(self):
        string = "x -> {x}; y -> {y}; z -> {z}"
        return string.format(x=self.__x, y=self.__y, z=self.__z)

    def get_length(self):
        return round(self.length, 2)