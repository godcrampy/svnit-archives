function stack = pop(stack)
    if length(stack)
        stack = stack(1:end - 1);
    end
end
