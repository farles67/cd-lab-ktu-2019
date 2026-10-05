function lexrun
    if test (count $argv) -ne 1
        echo "Usage: lexrun <file.l>"
        return 1
    end

    set file $argv[1]

    if not test -f "$file"
        echo "Error: File '$file' not found."
        return 1
    end

    echo "Running flex..."
    if not flex "$file"
        echo "Flex failed."
        return 1
    end

    set exe (string replace -r '\.l$' '' "$file")

    echo "Compiling..."
    if not gcc lex.yy.c -o "$exe"
        echo "Compilation failed."
        return 1
    end

    echo "Running..."
    ./"$exe"
end
