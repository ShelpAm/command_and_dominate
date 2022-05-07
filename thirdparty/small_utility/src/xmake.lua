target("small_utility")
    set_kind("static")

    set_objectdir("$(buildir)/obj/")
    add_includedirs("$(projectdir)/include/")
    add_linkdirs("$(projectdir)/lib/")

    add_files("**.cc")
