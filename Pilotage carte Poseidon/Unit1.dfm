object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 367
  ClientWidth = 682
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 304
    Top = 187
    Width = 57
    Height = 13
    Caption = 'Deconnect'#233
  end
  object Label2: TLabel
    Left = 128
    Top = 70
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 304
    Top = 70
    Width = 3
    Height = 13
  end
  object Label4: TLabel
    Left = 443
    Top = 48
    Width = 3
    Height = 13
  end
  object Label5: TLabel
    Left = 120
    Top = 48
    Width = 69
    Height = 13
    Caption = 'Temperature :'
  end
  object Label6: TLabel
    Left = 297
    Top = 46
    Width = 54
    Height = 13
    Caption = 'Compteur :'
  end
  object Label7: TLabel
    Left = 443
    Top = 67
    Width = 3
    Height = 13
  end
  object Connexion: TButton
    Left = 288
    Top = 140
    Width = 91
    Height = 25
    Caption = 'Connexion'
    TabOrder = 0
    OnClick = ConnexionClick
  end
  object ButtonChangeCompteur: TButton
    Left = 280
    Top = 295
    Width = 113
    Height = 25
    Caption = 'ChangerCompteur'
    TabOrder = 1
    OnClick = ButtonChangeCompteurClick
  end
  object ButtonOutput1ON: TButton
    Left = 63
    Top = 182
    Width = 129
    Height = 25
    Caption = 'Mettre sur ON output 1'
    TabOrder = 2
    OnClick = ButtonOutput1ONClick
  end
  object ButtonOutput1OFF: TButton
    Left = 128
    Top = 239
    Width = 129
    Height = 25
    Caption = 'Mettre sur OFF output 1'
    TabOrder = 3
    OnClick = ButtonOutput1OFFClick
  end
  object ButtonOutput2ON: TButton
    Left = 497
    Top = 182
    Width = 129
    Height = 25
    Caption = 'Mettre sur ON output 2'
    TabOrder = 4
    OnClick = ButtonOutput2ONClick
  end
  object ButtonOutput2OFF: TButton
    Left = 425
    Top = 239
    Width = 129
    Height = 25
    Caption = 'Mettre sur OFF output 2'
    TabOrder = 5
    OnClick = ButtonOutput2OFFClick
  end
  object Timer5: TTimer
    Enabled = False
    OnTimer = Timer5Timer
    Left = 648
    Top = 176
  end
end
