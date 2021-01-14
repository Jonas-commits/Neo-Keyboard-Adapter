import codecs
from collections import defaultdict

LEAF = '<>'
PREFIX_ID = 'OBJ_'
V_IDENT = 'const Node Compose::'

root = defaultdict(dict, ((LEAF, []),))


def attach(branch, trunk):
    if len(branch) == 0:
        return
    elif len(branch) == 1:
        trunk[LEAF].append(branch[0])
    else:
        node = branch[0]
        others = branch[1:]
        if node not in trunk:
            trunk[node] = defaultdict(dict, ((LEAF, []),))
        attach(others, trunk[node])


def dump(d, indent=0):
    for key, value in d.items():
        if key == LEAF:
            if value:
                print('   ' * indent + str(value[0]))
        else:
            print('  ' * indent + str(key))
            if isinstance(value, dict):
                dump(value, indent + 1)
            else:
                print('   ' * (indent + 1) + str(value))


def dump_c(d, indent=0):
    dictlen = len(d)
    if indent == 0:
        p = 'root'
    else:
        p = PREFIX_ID + str(id(d))

    print(V_IDENT + p + '[] PROGMEM = {')
    if dictlen > 1 :
        print('\t{{' + str((dictlen) % 256) + ', ' + str((dictlen) // 256) + '}, nullptr},')

    for key, value in d.items():
        if key != LEAF:
            print('\t{' + str(key) + ', ' + PREFIX_ID + str(id(value)) + '},')
        elif value:
            print('\t{' + str(value[0]) + '},')

    print('};\n')

    for key, value in d.items():
        if isinstance(value, dict):
            dump_c(value, indent + 1)


def parse(filename):
    with codecs.open(filename, encoding='utf-8', mode='r') as f:
        for x in f:
            sequence = []
            x = str(x)
            x = x.replace(' ', '')  # remove whitespace
            x = str(x.split('#')[0])  # remove comments
            symbols = x.split('>')
            suffix = symbols.pop()  # get all the unicode and other garbage
            for s in symbols:
                s = s.replace('<', '')
                sequence.append(s)
            if len(sequence) > 0:
                uc = suffix.split('\"')[1]
                if len(uc) == 1:
                    sequence.append(hex(ord(uc)))
                    attach(sequence, root)


if __name__ == '__main__':
    parse('base.module')
    #pprint(root)
    dump_c(root)
