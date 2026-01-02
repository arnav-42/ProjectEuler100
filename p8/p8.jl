function main()
    s = filter(isdigit, strip(read("input.txt", String)))
    digits = [Int(c - '0') for c in s]

    k = 13

    maxProd = -1
    bestIndex = 1

    for i in 1:(length(digits) - k + 1)
        prod = 1
        hasZero = false

        @inbounds for j in i:(i + k - 1)
            d = digits[j]
            if d == 0
                hasZero = true
                break
            end
            prod *= d
        end

        if !hasZero && prod > maxProd
            maxProd = prod
            bestIndex = i
        end
    end

    println(maxProd, " ", s[bestIndex:bestIndex + k - 1])
end

main()
