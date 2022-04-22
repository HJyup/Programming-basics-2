import modules


# Create a list with objects and output it
vectors_list = modules.create_list_with_classes()
modules.output_list_with_classes(vectors_list)

# Create list with length from objects list
lengths_list = modules.create_list_with_lengths(vectors_list)

# Print the biggest length
modules.output_values(lengths_list)
modules.find_biggest(lengths_list)