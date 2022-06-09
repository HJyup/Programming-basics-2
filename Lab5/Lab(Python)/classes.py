from abc import ABC, abstractmethod


# Parent-class that represent three int numbers
class TTriad(ABC):

    # Constructor
    def __init__(self, num1, num2, num3):
        self._numbers = [num1, num2, num3]

    # Getter
    def get_values(self):
        return self._numbers

    # Setter
    def set_values(self, new_num1, new_num2, new_num3):
        self._numbers = [new_num1, new_num2, new_num3]
        self._format_numbers()

    # Method that represent format numbers in child classes
    @abstractmethod
    def _format_numbers(self):
        pass

    # Increase and Decrease values
    def add_value(self, value, index):
        index = self.check_index(index)
        self._numbers[index - 1] += value
        self._format_numbers()

    def min_value(self, value, index):
        index = self.check_index(index)
        self._numbers[index - 1] -= value
        self._format_numbers()

    # Check if index is correct
    @staticmethod
    def check_index(index):
        if index > 3 or index < 1:
            return 3
        return index

    # String representation of class
    def __repr__(self):
        return str(self._numbers[0]) + " " + str(self._numbers[1]) + \
               " " + str(self._numbers[2])


# Child-class that represent time
class TTime(TTriad):

    # Constructor
    def __init__(self, seconds, minutes, hours):
        super().__init__(seconds, minutes, hours)
        self._format_numbers()

    # Method that represent format numbers
    def _format_numbers(self):
        for i in range(0, 2):
            if self._numbers[i] > 60:
                self._numbers[i + 1] += 1
                self._numbers[i] -= 60
            elif self._numbers[i] < 0:
                self._numbers[i + 1] -= 1
                self._numbers[i] += 60
        if 0 > self._numbers[2] or self._numbers[2] > 24:
            self._numbers[2] = 0

    # String representation of class
    def __repr__(self):
        str_nums = [str(num) for num in self._numbers]
        for i in range(0, len(str_nums)):
            if len(str_nums[i]) == 1:
                str_nums[i] = '0' + str_nums[i]
        return str_nums[0] + ':' + str_nums[1] + ':' + str_nums[2]


# Child-class that represent date
class TDate(TTriad):

    # Constructor
    def __init__(self, num1, num2, num3):
        super().__init__(num1, num2, num3)
        self._format_numbers()

    # Method that represent format numbers
    def _format_numbers(self):
        # Format days.
        self.__check_days()

        if self._numbers[1] > 12:
            self._numbers[2] += 1
            self._numbers[1] -= 12
        elif self._numbers[1] < 0:
            self._numbers[2] -= 1
            self._numbers[1] += 12

    # Checks days in months and format values
    def __check_days(self):
        if self.__is_leap_year(self._numbers[2]):
            month_max_value = 29
        else:
            month_max_value = 28 + (self._numbers[1] + self._numbers[1] // 8) % 2 + 2 % \
                              self._numbers[1] + 1 // self._numbers[1] * 2

        if self._numbers[0] > month_max_value:
            self._numbers[1] += 1
            self._numbers[0] -= month_max_value
        elif self._numbers[0] < 0:
            self._numbers[1] -= 1
            self._numbers[0] += month_max_value

    @staticmethod
    def __is_leap_year(yrs):
        year = yrs + 1
        return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0

    # String representation of class
    def __repr__(self):
        str_nums = [str(num) for num in self._numbers]
        for i in range(0, len(str_nums)):
            if len(str_nums[i]) == 1:
                str_nums[i] = '0' + str_nums[i]
        return str_nums[0] + '.' + str_nums[1] + '.' + str_nums[2]
