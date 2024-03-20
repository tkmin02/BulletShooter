# BULLET-SHOOTER


■ 制作人数

　一人


■ 製作期間 

　2024年1月上旬～3月中旬（約2か月半）


■ 言語

　C++


■ ライブラリ

・Dxライブラリ（program/dxlib_ext)

・講師配布の専用ライブラリ（program/library)

・私のライブラリ(program/game)


■ コードについて


　1. この作品では「std::shared_ptr」を「Shared」に省略したスマートポインタを使用しています。

　2. SceneManagerクラスは講師から提供された雛形を使用しています。

　3. 名前空間「dxe」はDxライブラリ、「tnl」は講師のライブラリ、「inl」は私のライブラリです。

　4.「東方Project」と呼ばれる著作物の一部（キャラクター名・弾幕名など）をクラス名や関数名、変数名に引用している部分があります。
 

■ ゲームの説明

　このゲームは３Dの弾幕シューティングゲームです。迫り来る弾を回避しながら敵を倒しましょう。


■ 開発目的


　多くの弾を制御するための
 
「メモリ管理」、「技術」、より高度な「三次元座標」などについて学びたかった事、

 
　また、「東方Project」と呼ばれる著作物の

　独自性のある２D弾幕シューティングゲームを３Dで表現してみたいと思った事が主な理由です。　


■ 構成


　タイトル　⇒　難易度選択　⇒　プレイ　⇒　リザルト

 　コードは　

　SceneTitle　⇒　SceneSelectDifficulty　⇒　ScenePlay　⇒　SceneResult　　が一連の流れとなっています。



 ■ 操作方法

・移動　　　　　　　キーボードWASDキー、ゲームパッド十字キー

・前進　　　　　　　キーボードSpaceキー、ゲームパッドL1、LB

・スロー移動　　　　キーボードShiftキー、ゲームパッド△、Y

・弾発射　　　　　　マウス左、ゲームパッド〇、B

・カメラ固定　　　　マウス右、ゲームパッドR1、RB

・ターゲット変更　　マウスホイール

・視点操作　　　　　マウス、ゲームパッド左スティック"

・ボム　　　　　　　マウス中央

・ポーズ画面　　　　キーボード左Altキー


　　※ このゲームを起動するとマウスカーソルがオフになります。ゲームの終了には、エスケープキーを押してください。


■ アピールポイント

　1.メモリ管理

　　　各ステージのボスは固有の3種類の弾幕でプレイヤーを攻撃しますが、この大量の弾の制御を処理落ちせずに実装しています。


　2.難易度対応

　　　以前の作品で出来ていなかった難易度調整を、本作品ではしっかりと実装しています。
 
　　難易度ごとに敵やプレイヤーのステータスが変わり、それぞれの難易度に応じてゲームを楽しむことが出来ます。


　3.オブジェクト指向設計の意識

　　　本作品ではオブジェクト指向の概念である「カプセル化」及び「継承」を特に意識した設計をしています。
   
　　このようにしたことでデータの「保守性」や機能の「拡張性」が得られました。


　4.名前空間の使用

　　　名前空間を使用したことで、名前の衝突回避をはじめデータのアクセス制御やクラス管理などにも対応しやすくなりました。


　5.カスタム例外クラス

　　　独自の例外クラスを作成し、あらゆるクラスで使用できるようにモジュール化しました。
 

 ■ 課題点

 　1.プレイヤーの多様化


　　　現状選べるプレイヤーは１種類のみで、攻撃手段もワンパターンになっています。

　　これを複数のプレイヤーを導入することによって、プレイ体験により幅を持たせたいと考えています。


　2.弾幕表現

　　　一部の弾幕は意図した正確な動作をしていません。現状は、より完璧な動作にするためには修正が必要となっています。 

■ 開発の参考にしたゲーム

　　https://store.steampowered.com/app/1299420/Touhou__Shooting_Star/?l=japanese


 
■ 使用音源をお借りしたサイト

サイト名：ユーフルカ

https://youfulca.com/
