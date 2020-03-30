object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 231
  ClientWidth = 505
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
    Left = 234
    Top = 104
    Width = 57
    Height = 13
    Caption = 'Deconnecte'
  end
  object Button1: TButton
    Left = 208
    Top = 160
    Width = 113
    Height = 25
    Caption = 'Envoie requete bdd'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 40
    Width = 113
    Height = 25
    Caption = 'Connection BDD'
    TabOrder = 1
    OnClick = Button2Click
  end
end
