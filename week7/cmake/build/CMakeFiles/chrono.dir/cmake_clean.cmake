file(REMOVE_RECURSE
  "libchrono.a"
  "libchrono.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/chrono.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
