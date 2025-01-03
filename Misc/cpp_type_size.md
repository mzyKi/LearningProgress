## Basic Type Size

depends on compiler bits

#### 16bits compiler
* char : 1B
* char * : 2B
* short int : 2B
* unsigned int : 2B
* float : 4B
* double : 8B
* long : 4B
* long long : 8B
* unsigned long : 8B

#### 32bits compiler
* char : 1B
* char *: 4B
* unsigned int : 4B
* float : 4B
* double : 8B
* long : 4B
* long long : 8B
* unsigned long : 4B

#### 64bits compiler
* char : 1B
* char *: 8B
* short int : 2B
* int : 4B
* unsigned int : 4B
* float : 4B
* double : 8B
* long : 8B
* long long : 8B
* unsigned long : 8B

## Class Type Size
```cpp
class A{

};

class B{
    void foo();
}

class C{
    static int i;
    void goo();
}
```

Type sizes of the above are all 1B.

```cpp
class A{
    virtual void foo() = 0;
}
```
Type size of the above is 4B because of virtual function table pointer.

#### Alignment Rule
* The size of a structure is equal to an integer multiple of the size of the largest member in the structure
* The offset of the first address of a member in a structure relative to the first address of the structure is an integer multiple of its type size. For example, the address offset of a double type member relative to the first address of the structure should be a multiple of 8.