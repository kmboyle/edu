# import os
#
# bsize = 16384
# fin = os.open("foo", os.O_RDONLY)
# fout = os.open("bar", os.O_WRONLY | os.O_CREAT, 0o644)
#
# # This doesn't work because assignments don't return a value
#
# while (buf = os.read(fin, bize)) :
#     os.write(fout, buf)
#
#     os.close(fin)
#     os.close(fout)
    

with open('foo', 'rb') as fin:
    with open('bar', 'wb') as fout:
        fout.write(fin.read())
