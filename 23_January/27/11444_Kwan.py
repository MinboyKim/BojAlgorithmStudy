def mul(n):
    if n==1:
        return [[1,1],[1,0]]
    else:
        mat = mul(n//2)
        mat2 = [[0, 0], [0, 0]]
        mat2[0][0] = (mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0]) % 1000000007
        mat2[0][1] = (mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1]) % 1000000007
        mat2[1][0] = (mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0]) % 1000000007
        mat2[1][1] = (mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1]) % 1000000007
        if n & 1:
            mat[0][0] = (mat2[0][0] + mat2[1][0]) % 1000000007
            mat[0][1] = (mat2[0][1] + mat2[1][1]) % 1000000007
            mat[1][0] = mat2[0][0]
            mat[1][1] = mat2[0][1]
            return mat
        return mat2
n = int(input())
mat = mul(n)
print(mat[0][1])