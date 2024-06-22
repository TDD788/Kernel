import sys

def merge_dtbo(output_file, input_files):
    with open(output_file, 'wb') as outfile:
        for fname in input_files:
            with open(fname, 'rb') as infile:
                outfile.write(infile.read())

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("How to Use: python3 merge_dtbo.py <output.img> <input1.dtbo> <input2.dtbo> ...")
        sys.exit(1)

    output_file = sys.argv[1]
    input_files = sys.argv[2:]

    merge_dtbo(output_file, input_files)