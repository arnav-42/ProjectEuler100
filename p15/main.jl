using Printf

function main()
    t0 = time_ns()

    ans = binomial(big(40), big(20))

    t1 = time_ns()

    cpu_time_used = (t1 - t0) / 1e9
    @printf("Answer: %d\n", ans)
    @printf("Time: %f seconds\n", cpu_time_used)
end

main()
