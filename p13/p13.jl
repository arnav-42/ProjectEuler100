s = read("input.txt", String)
nums = parse.(BigInt, split(replace(s, "<br>" => "\n")))

t0 = time()
total = BigInt(0)
for num in nums
    global total += num
end
t1 = time()

println("Time taken: ", t1 - t0, " seconds")
println(total)

#Time taken: 0.009465932846069336 seconds
#5537376230390876637302048746832985971773659831892672
