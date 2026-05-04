def is_empty(filename: str) -> bool:
    # Check if the input_file is empty
    with open(filename) as f:
        x = f.read().strip()
    return len(x) == 0


def compare_answer(
    actual_lines: list[str], expected_lines: list[str], rstrip=True
) -> tuple[bool, str]:
    """Compares two lists of strs and returns Verdict/Result.
    Ignores trailing empty lines for convenience.
    Codeforces is lenient with trailing whitespace.
    """

    def preprocess_lines(lines: list[str]) -> list[str]:
        # rstrip if flag
        lines = [line.rstrip() if rstrip else line for line in lines]
        # remove trailing empty
        while len(lines) and len(lines[-1]) == 0:
            lines.pop()
        return lines

    actual_lines = preprocess_lines(actual_lines)
    expected_lines = preprocess_lines(expected_lines)

    if len(actual_lines) != len(expected_lines):
        return (
            False,
            f"😥 WA: diff # lines. expected={len(expected_lines)}, actual={len(actual_lines)}",
        )

    diff = 0
    for actual_line, expected_line in zip(actual_lines, expected_lines):
        if actual_line != expected_line:
            diff += 1

    if diff:
        return False, f"😥 WA: {diff}/{len(actual_lines)} lines are different"

    return True, "✅ AC"
