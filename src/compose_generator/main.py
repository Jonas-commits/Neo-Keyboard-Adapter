import codecs

def parse(filename):
    with codecs.open(filename, encoding='utf-8', mode='r') as f:
        for x in f:
            sequence = []
            x = str(x)
            x = x.replace(' ', '') #remove whitespace
            x = str(x.split('#')[0]) #remove comments
            symbols = x.split('>')
            suffix = symbols.pop() # get all the unicode and other garbage
            for s in symbols:
                s = s.replace('<', '')
                sequence.append(s)
            if len(sequence) > 0:
                uc = suffix.split('\"')[1]
                if len(uc) == 1:
                    uc_number = hex(ord(uc))
                    print(sequence, uc_number)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    parse('base.module')

