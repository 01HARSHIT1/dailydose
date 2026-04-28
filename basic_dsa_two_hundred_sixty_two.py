"""
Basic DSA - Simplify Path
Given a string path, which is an absolute path (starting with '/'), convert it to the
simplified canonical path.
"""


def simplify_path(path):
    """
    Stack of path components.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    stack = []
    for part in path.split("/"):
        if part == "" or part == ".":
            continue
        if part == "..":
            if stack:
                stack.pop()
        else:
            stack.append(part)
    return "/" + "/".join(stack)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Simplify Path")
    print("=" * 60)

    print(simplify_path("/home/"))  # /home
    print(simplify_path("/home//foo/"))  # /home/foo
    print(simplify_path("/home/user/Documents/../Pictures"))  # /home/user/Pictures
    print(simplify_path("/../"))  # /
    print(simplify_path("/.../a/../b/c/../d/./"))  # /.../b/d
