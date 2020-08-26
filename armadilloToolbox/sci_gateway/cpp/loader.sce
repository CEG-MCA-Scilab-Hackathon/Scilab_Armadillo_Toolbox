// This file is released under the 3-clause BSD license. See COPYING-BSD.
// Generated by builder.sce : Please, do not edit this file
// ----------------------------------------------------------------------------
//
libarmadilloToolbox_path = get_absolute_file_path('loader.sce');
//
// ulink previous function with same name
[bOK, ilib] = c_link('libarmadilloToolbox');
if bOK then
  ulink(ilib);
end
//
list_functions = [ 'armaMatFunc';
                   'armaMat';
                   'armaVec';
                   'armaStat';
                   'armaClust';
                   'armaImage';
                   'armaDenseMat';
];
addinter(libarmadilloToolbox_path + filesep() + 'libarmadilloToolbox' + getdynlibext(), 'libarmadilloToolbox', list_functions);
// remove temp. variables on stack
clear libarmadilloToolbox_path;
clear bOK;
clear ilib;
clear list_functions;
// ----------------------------------------------------------------------------
