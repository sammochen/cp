def is_empty(filename: str):
    # Check if the input_file is empty
    with open(filename) as f:
        x = f.read().strip()
    return len(x) == 0


def read_output(filename):
    with open(filename) as f:
        text = f.read()

    # Remove trailing space(s) before new lines
    lines = text.split("\n")
    lines = [line.rstrip() for line in lines]

    return "\n".join(lines)
