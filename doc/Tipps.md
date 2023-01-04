# Pay attension to type of a variable, expecially by operations on variables with different types

# For example, in following code snippet, the _size()_ function returns a variable in type _size_t_, which is unsigned. But on the left side of the operation _end - myVec.size()_, the variable _end_ has type signed int. In case the result of above operation being nagative, the actual output would be a very big positive number, just because the type _size_t_ can not store negative values.

```cpp
vector<int> myVec(10, 1);
int start, end = 0;
// the following statement will alway return true, because myVec.size() is an unsigned variable,
// but the result of end - myVec.size() + 1 is negative
while (start <= end - myVec.size() + 1)
{
    // do something here
}
// this would give the expected behaviour
while (start <= end - static_cast<int>(myVec.size()) + 1)
{
    // do something here
}
// this would also give the expected behavior
int len = myVec.size();
while (start <= end - len)
{

}
```
