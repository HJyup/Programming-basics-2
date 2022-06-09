from modules import *

# Create a list with dates and times
list_with_times_dates = create_lists_with_objects()

# Output objects
print("\nObjects that represent times and dates: ")
output_objects(list_with_times_dates)

# Create a list with dates that can be represented like time
corrects_list_with_times_dates = find_correct_dates_and_time(list_with_times_dates)

# Output objects
print("\nDates that can be represented like time:  ")
output_objects(corrects_list_with_times_dates)

# Change and output changed objects
list_with_times_dates = change_list(list_with_times_dates, corrects_list_with_times_dates)
print("\nChanged dates and times: ")
output_objects(list_with_times_dates)

