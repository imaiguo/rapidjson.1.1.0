

## 编译测试程序

```bash
> vcvars64.bat
> mkdir build & cd build
> cmake ..
> ninja
```


## 跑测指定的测试用例

```bash
> .\unittest.exe  --gtest_filter="*Issue399"
```

