object Form1: TForm1
  Left = 270
  Top = 202
  Width = 669
  Height = 540
  Caption = 'Form1'
  Color = clSilver
  TransparentColorValue = clPurple
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 64
    Width = 34
    Height = 24
    Caption = 'A = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 152
    Top = 128
    Width = 33
    Height = 24
    Caption = 'B = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 152
    Top = 192
    Width = 33
    Height = 24
    Caption = 'Z = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 184
    Top = 64
    Width = 121
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 184
    Top = 128
    Width = 121
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 184
    Top = 192
    Width = 121
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = 'Edit3'
  end
  object RadioGroup1: TRadioGroup
    Left = 336
    Top = 72
    Width = 185
    Height = 145
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' f:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Items.Strings = (
      'f = 2*x'
      'f = x*x'
      'f = x/3')
    ParentFont = False
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 152
    Top = 240
    Width = 369
    Height = 113
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Button1: TButton
    Left = 264
    Top = 384
    Width = 139
    Height = 41
    Caption = #1042#1067#1055#1054#1051#1053#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
  end
end
