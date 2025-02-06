## Exercise 1

On the root of the repository create a `MODULE.bazel` file, looking like this:

```python
module(name = "my_module", version="1.0")

bazel_dep(name = "rules_cc", version = "0.0.1") # correct version?
```

I did first on a single file

```python
cc_library(
    name = "shapesLib",
    srcs = ["shape/shape.cpp"],
    hdrs = ["shape/inc/shape.hpp"],
)

cc_library(
    name = "shapes",
    srcs = [
        "shape/shape.cpp",
        "circle/circle.cpp",
        "rectangle/rectangle.cpp"],
    hdrs = [
        "circle/inc/circle.hpp",
        "rectangle/inc/rectangle.hpp"],
    deps = [
        ":shapesLib",
    ],
)

cc_binary(
    name = "finalBinary",
    srcs = ["main.cpp"],
    deps = [
        ":shapes"
    ],
)
```

Splitting:

File `cli/shape/BUILD`:
```python
cc_library(
    name = "shapeLib",
    srcs = ["shape.cpp"],
    hdrs = ["inc/shape.hpp"],
    visibility = ["//visibility:public"],
)
```

File `cli/circle/BUILD`:
```python 
cc_library(
    name = "circleLib",
    srcs = ["circle.cpp"],
    hdrs = ["inc/circle.hpp"],
    deps = [
        "//project/cli/shape:shapeLib"
    ],
    visibility = ["//visibility:public"],
)
```

File `cli/rectangle/BUILD` same as `cli/circle/BUILD`:
```python
cc_library(
    name = "rectangleLib",
    srcs = ["rectangle.cpp"],
    hdrs = ["inc/rectangle.hpp"],
    deps = [
        "//project/cli/shape:shapeLib"
    ],
    visibility = ["//visibility:public"],
)

```

File `cli/BUILD`
```python
cc_binary(
    name = "finalBinary",
    srcs = ["main.cpp"],
    deps = [
        "//project/cli/shape:shapeLib",
        "//project/cli/rectangle:rectangleLib",
        "//project/cli/circle:circleLib",
    ],
)
```

