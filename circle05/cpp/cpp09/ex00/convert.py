import csv

def convert_csv_to_txt(csv_file, txt_file):
    with open(csv_file, 'r') as file:
        csv_reader = csv.reader(file)
        with open(txt_file, 'w') as output_file:
            for row in csv_reader:
                formatted_row = ' | '.join(row)
                output_file.write(formatted_row + '\n')

# 사용 예시
csv_file = './data.csv'
txt_file = './input.txt'
convert_csv_to_txt(csv_file, txt_file)
