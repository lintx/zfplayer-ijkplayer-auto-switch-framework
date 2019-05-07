##  使用ZFPlayer+IJKPlayer，并自动切换IJKPlayer Framework的Demo
本Demo只是整合了ZFPlayer和IJKPlayer，并加上自动切换Framework功能，播放相关的代码都是使用的ZFPlaery的代码。

### 关于ZFPlayer
[ZFPlayer](https://github.com/renzifeng/ZFPlayer)现在是用Framework的方式设计，但是因为不喜欢用pod导入，也没有研究生成Framework，所以干脆将文件直接复制到工程目录下，并将`import`头文件的方式全部由`<>`修改为`""`方式，如果你不用这种方式，可以直接使用pod或者其他方式导入。
本工程中只加入了部分ZFPlayer的使用方式，更多使用方式请见ZFPlayer的主页。

### 关于IJKPlayer
工程中附带的[IJKPlayer](https://github.com/bilibili/ijkplayer)，2个Framework由0.8.8版本编译而成，加入了openssl，其他均为默认配置。

### 自动切换IJKPlayer Framework
网上对IJKPlayer的2种Framework处理，都是将模拟器和真机的Framework合并，以便方便的在模拟器和真机中运行app，但是这样不仅AppStore支持不好，而且会将无用的模拟器用Framework文件打包到应用商店二进制文件中，增加app体积。
通过搜索，发现可以在scheme设置中增加pre-actions来执行编译前的指令，经过摸索，已经实现了使用模拟器运行和针对真机打包时自动更换Framework文件，方法如下：
1. 点击Xcode左上角的target，然后点击`Edit Scheme`菜单。
2. 展开`Build`选项（Build不管是run还是archive，都会触发）。
3. 选择`Pre-actions`。
4. 点击下方的`+`按钮，增加一个action。
5. 在上方的`Provide build settings from`后面选择对应的target。
6. 在中间的脚本框中输入以下脚本：
```shell
# 工程目录
rootPath = "${PROJECT_DIR}/zfplayer+ijkplayer+autoframework/"
# 需要编译的Framework所在目录，将把对应的Framework复制到这个目录
targetPath="Framework/build"
# 模拟器Framework所在目录（源目录）
simulatorFile="Framework/simulator/*"
# 真机Framework所在目录（源目录）
iphoneFile="Framework/iphone/*"

# 将脚本日志记录在指定文件
exec > ${rootPath}prebuild.log 2>&1
echo "cp framework file start."

# 切换工作目录
cd "${rootPath}"
echo "sdk_name is : ${SDK_NAME}"
sourceFiles=""
# 根据${SDK_NAME}判断是模拟器还是真机
if [[ "${SDK_NAME}" == iphonesimulator* ]]; then
# ${SDK_NAME}以iphonesimulator开头，表示是模拟器
    sourceFiles=$simulatorFile
else
    sourceFiles=$iphoneFile
fi
echo "build to simulator, cp $sourceFiles to $targetPath"
cp -f -r $sourceFiles $targetPath
echo "cp framework file done."
```

最后，随意将模拟器或真机的Framework复制一份到`targetPath`，然后将`targetPath`目录下的Framework添加到工程中。

注：
1. 以上代码是本工程使用的脚本，如需使用请修改对应的目录。
2. 添加Framework时不要选中`Copy items if needed`，并保证工程设置-target-Build Settings-Search Paths-Framework Search Paths中有脚本中的`targetPath`目录。
3. 以上脚本也适用于其他区分真机、模拟器的Framework，只需要将所有区分的版本分别放入`simulatorFile`所在目录和`iphoneFile`所在目录，并随意复制一份到`targetPath`后添加进工程即可。

![屏幕快照 2019-05-07 下午10.10.07.png](https://i.loli.net/2019/05/07/5cd191def2916.png)
![屏幕快照 2019-05-07 下午10.09.32.png](https://i.loli.net/2019/05/07/5cd191df2a245.png)
