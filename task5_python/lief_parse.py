import lief

binary = lief.parse('./build/libsecret.so')

symb_vis = binary.dynamic_symbols[0].visibility
for i, symb in enumerate(binary.dynamic_symbols):
    if symb.name == '_Z12authenticatePKc':
        symb.visibility = symb_vis
        print(symb.name)
        print(symb.visibility)

binary.write('./build/libsecretnew.so')
