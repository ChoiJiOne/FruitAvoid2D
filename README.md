# FruitAvoid2D
- 2D 과일 피하기 게임
<br><br>


## 프로젝트 선정 배경

**상용 게임 엔진 (ex. Unreal Engine, Unity ...) 없이** C++로 간단하게 게임 개발을 하고자 이 프로젝트를 진행하게 되었습니다.
<br><br>


## 프로젝트 목표

이 프로젝트는 다음과 같은 **목표**를 가지고 있습니다.  
1. C++를 사용하여 게임을 제작합니다.  
2. 개발 환경 구성 (Visual Studio 솔루션)을 자동화 합니다.  
3. 유저가 플레이 할 수 있도록 Github 에 최적화된 실행 파일을 배포합니다.
4. 다른 개발자가 확장 및 유지할 수 있도록 오픈 소스를 유지합니다.
<br><br>


## 프로젝트에서 사용하는 서드 파티 라이브러리

이 프로젝트에서는 다음과 같은 라이브러리를 사용합니다.  
이때, C++의 단점 중 하나로 서드 파티 라이브러리 관리의 어려움이 있습니다.  
따라서, 이를 극복하고자 Single Header Library 위주로 사용합니다.  
- [SDL2](https://github.com/libsdl-org/SDL) : 윈도우 창 생성, 입력 처리, 화면 렌더링을 수행하는 라이브러리입니다.
- [spdlog](https://github.com/gabime/spdlog) : 로그 출력 및 저장을 수행하는 라이브러리입니다.
- [json](https://github.com/nlohmann/json) : json 파일을 파싱하고 저장하는 라이브러리입니다.
- [stb](https://github.com/nothings/stb) : 이미지 파일 로딩, 저장, 크기 조절 및 트루 타입 폰트 로딩, 폰트 글리프 데이터 생성 등의 기능을 수행하는 라이브입니다.
<br><br>


## 사전 준비

이 프로젝트를 빌드 및 유지 개발을 진행하기 위해서는 다음 요소가 필요합니다.
- [Visual Studio 2019 혹은 그 이상](https://visualstudio.microsoft.com/ko/)
- [git](https://git-scm.com/)
<br><br>


## 빌드 방법

프로젝트 빌드를 수행하기 위한 절차는 다음과 같습니다.  
1. 터미널 혹은 CMD에서 원하는 디렉토리로 이동한 뒤 `git clone https://github.com/ChoiJiOne/FruitAvoid2D` 를 수행합니다.
    - 원하는 폴더에서 터미널 혹은 CMD를 실행한 뒤에 진행해도 문제 없습니다.
2. `cd FruitAvoid2D` 를 실행하여 디렉토리를 이동한 후 `GenerateProjectFiles.bat` 를 실행합니다.
3. 생성된 `FruitAvoid2D` 폴더 하위의 `FruitAvoid2.sln` 를 실행합니다.
    - 이때, 사전 준비 요소들이 필요합니다.
4. `Ctrl + B` 를 입력하여 프로젝트를 빌드합니다.
<br><br>


## 플레이 방법

2D 과일 피하기 게임을 플레이 하기 위한 방법은 다음과 같습니다.
<br><br>
