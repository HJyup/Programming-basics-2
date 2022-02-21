import modules

# Variable with name of files
input_file = 'input.txt'
output_file = 'output.txt'

# Create input.txt
input_list = modules.create_input_text()
modules.create_file(input_file, input_list)
modules.read_txt_file(input_file)

# Change content of input file
output_list = modules.create_new_content(input_list)

# Save content to output file
modules.create_file(output_file, output_list)
modules.read_txt_file(output_file)
