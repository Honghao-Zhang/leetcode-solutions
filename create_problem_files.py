import os

def createHeader(name, folder, namespace='default'):
    folder_path = './include/'+folder
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    header_path = folder_path+'/'+name+'.h'
    if not os.path.exists(header_path):
        with open(header_path, 'w') as header_file:
            header_file.write('#ifndef MY_SOLUTIONS_'+name.upper()+'_H\n')
            header_file.write('#define MY_SOLUTIONS_'+name.upper()+'_H\n')
            header_file.write('\n')
            if namespace == 'default':
                header_file.write('namespace '+name+'\n')
            else:
                header_file.write('namespace '+namespace+'\n')
            header_file.write('{\n')
            header_file.write('\t'+'class Solution\n')
            header_file.write('\t{\n')
            header_file.write('\t'+'public:\n')
            header_file.write('\t};\n')
            header_file.write('};\n')
            header_file.write('#endif\n')
    else:
        print(name+'.h already exists!')

def createSourceFile(name, folder, header_name, namespace='default', is_test_file = False):
    if not is_test_file:
        folder_path = './src/'+folder
    else :
        folder_path = './test/'+folder
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    # create new cpp file
    cpp_path = folder_path+'/'+name+'.cpp'
    if not os.path.exists(cpp_path):
        with open(cpp_path, 'w') as cpp_file:
            cpp_file.write('#include \"'+folder+ '/'+header_name+'.h\"\n')
            if is_test_file:
                cpp_file.write('#include <gtest/gtest.h>')
            cpp_file.write('\n')
            cpp_file.write('using namespace std;\n')
            if namespace == 'default':
                cpp_file.write('using namespace '+name+';\n')
            else:
                cpp_file.write('using namespace '+namespace+';\n')
            cpp_file.write('\n')
    else:
        print(name+'.cpp already exists!')
    # modify cmakelist
    if not is_test_file:
        cmake_path = './src/CMakeLists.txt' 
    else :
        cmake_path = './test/CMakeLists.txt'
    if not os.path.exists(cmake_path):
        print(cmake_path + ' does not exist !')
    else :
        with open(cmake_path, '+r') as cmake_file:
            contents = cmake_file.readlines()
            for idx, line in enumerate(contents):
                if line.startswith('add_library') or line.startswith('add_executable'):
                    contents.insert(idx+1, '\t./'+folder+'/'+name+'.cpp\n')
                    break
            cmake_file.seek(0)
            cmake_file.writelines(contents)
            
             
if __name__ == '__main__':
    problem_type = 'dynamic_programming'
    header_name  = 'dp'
    problem_name = 'p279_perfect_squares'
    namespace    = 'dp'
    createHeader(header_name, problem_type, namespace)
    createSourceFile(problem_name, problem_type, header_name, namespace)
    createSourceFile(problem_name+'_test', problem_type, header_name, namespace, True)