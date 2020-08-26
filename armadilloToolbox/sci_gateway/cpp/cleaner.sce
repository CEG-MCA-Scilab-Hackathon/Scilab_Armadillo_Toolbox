// This file is released under the 3-clause BSD license. See COPYING-BSD.
// Generated by builder.sce : Please, do not edit this file
// cleaner.sce
// ------------------------------------------------------
curdir = pwd();
cleaner_path = get_file_path('cleaner.sce');
chdir(cleaner_path);
// ------------------------------------------------------
if fileinfo('loader.sce') <> [] then
  mdelete('loader.sce');
end
// ------------------------------------------------------
if fileinfo('libarmadilloToolbox.so') <> [] then
  mdelete('libarmadilloToolbox.so');
end
// ------------------------------------------------------
if fileinfo('libarmadilloToolbox.cpp') <> [] then
  mdelete('libarmadilloToolbox.cpp');
end
// ------------------------------------------------------
if fileinfo('libarmadilloToolbox.hxx') <> [] then
  mdelete('libarmadilloToolbox.hxx');
end
// ------------------------------------------------------
if fileinfo('libarmadilloToolbox.h') <> [] then
  mdelete('libarmadilloToolbox.h');
end
// ------------------------------------------------------
chdir(curdir);
// ------------------------------------------------------
