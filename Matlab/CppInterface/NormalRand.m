function X = NormalRand(Rows, Cols, Seed, Generator)

if(Generator <= 0)
    rng(Seed, 'twister')
end
if(Generator == 1)
    rng(Seed, 'v5normal')
end
if(Generator >= 2)
    rng(Seed, 'v4')
end

X = randn(Rows, Cols);