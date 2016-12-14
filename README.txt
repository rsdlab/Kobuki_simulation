
##########################################################
RTミドルウェアコンテスト2016
移動ロボット開発支援のためのRTコンポーネント群
##########################################################


Documents内に操作マニュアルを参考にしてご利用ください．

各ファイルの説明

・PoseConverterRTC
 Choreonoidのモデル座標を出力するデータポート型であるTimedPose3DをMobileRobotNavigationFrameworkに対応するTimedPose2Dへと変換するコンポーネント

・VelocityConverterRTC
 MobileRobotNavigationFrameworkで用いられるSFMLJoystickの出力ポートのデータ型であるTimedVelocity2DをChoreonoidのモデルへの速度を入力ポートのデータ型であるTimedDoubleSeqへと変更するコンポーネント

・RangeDataViewerRTC
 ChoreonoidでのRangeDataを出力するためのコンポーネント
※こちらのコンポーネントは産総研の金広様がgithub上で公開しているhrpsys-baseに同封されているRangeDataViewerのソースコードを単独RTC化したものであり，以下のページを参考にしています．
URL:http://docs.ros.org/indigo/api/hrpsys/html/classRangeDataViewer.html
こちらのコンポーネントはOpenCVの関数を用いているため，コンパイルする際にはOpenCVをインストールしてください．また,こちらのコンポーネントはRangeデータを確認するためのものでありますのでシミュレーションを行うに当たって必ず必要となってくるものではありません

・Documents
　操作マニュアルが入ったファイル

・model_project
　Choreonoid用のモデルファイルやプロジェクトが入ったファイル

ご不明な点がございましたら以下にご連絡ください


##########################################################
名城大学　ロボットシステムデザイン研究室
Email : 130447091@ccmailg.meijo-u.ac.jp
##########################################################
