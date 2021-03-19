object MyForm: TMyForm
  Left = 0
  Top = 0
  Caption = 'Computa'#231#227'o Gr'#225'fica'
  ClientHeight = 845
  ClientWidth = 1540
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object lbViewport: TLabel
    Left = 21
    Top = 527
    Width = 27
    Height = 13
    Caption = '(0, 0)'
  end
  object lbMundo: TLabel
    Left = 494
    Top = 528
    Width = 27
    Height = 13
    Alignment = taRightJustify
    Caption = '(0, 0)'
  end
  object MyPanel: TPanel
    Left = 20
    Top = 20
    Width = 502
    Height = 502
    Caption = 'MyPanel'
    TabOrder = 0
    object img: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = imgMouseDown
      OnMouseMove = imgMouseMove
      ExplicitLeft = 200
      ExplicitTop = 216
      ExplicitWidth = 105
      ExplicitHeight = 105
    end
  end
  object Panel1: TPanel
    Left = 542
    Top = 322
    Width = 210
    Height = 200
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 1
    DesignSize = (
      208
      198)
    object Label8: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'MUDAR COORDENADAS DO MUNDO'
      ExplicitWidth = 190
    end
    object Label9: TLabel
      Left = 10
      Top = 38
      Width = 30
      Height = 13
      Alignment = taCenter
      Caption = 'Xwmin'
    end
    object Label10: TLabel
      Left = 120
      Top = 87
      Width = 34
      Height = 13
      Alignment = taCenter
      Caption = 'Ywmax'
    end
    object Label11: TLabel
      Left = 10
      Top = 87
      Width = 30
      Height = 13
      Alignment = taCenter
      Caption = 'Ywmin'
    end
    object Label12: TLabel
      Left = 120
      Top = 38
      Width = 34
      Height = 13
      Alignment = taCenter
      Caption = 'Xwmax'
    end
    object edXwmin: TEdit
      Left = 10
      Top = 54
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 0
      Text = '-250'
    end
    object edYwmax: TEdit
      Left = 120
      Top = 103
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 3
      Text = '250'
    end
    object edYwmin: TEdit
      Left = 10
      Top = 103
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 2
      Text = '-250'
    end
    object edXwmax: TEdit
      Left = 120
      Top = 54
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 1
      Text = '250'
    end
    object btAtualizarMundo: TButton
      Left = 10
      Top = 135
      Width = 191
      Height = 25
      Caption = 'ATUALIZAR'
      TabOrder = 4
      OnClick = btAtualizarMundoClick
    end
    object btnZerarCoordenadas: TButton
      Left = 10
      Top = 166
      Width = 190
      Height = 25
      Caption = 'ZERAR'
      TabOrder = 5
      OnClick = btnZerarCoordenadasClick
    end
  end
  object Panel2: TPanel
    Left = 542
    Top = 20
    Width = 210
    Height = 280
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel2'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 2
    object Label3: TLabel
      Left = 10
      Top = 10
      Width = 190
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 'CONTROLE DOS POL'#205'GONOS'
    end
    object Label4: TLabel
      Left = 10
      Top = 25
      Width = 45
      Height = 13
      Caption = 'Poligonos'
    end
    object Label6: TLabel
      Left = 10
      Top = 125
      Width = 33
      Height = 13
      Caption = 'Pontos'
    end
    object btDesenharPoligono: TButton
      Left = 10
      Top = 226
      Width = 190
      Height = 38
      Caption = 'DESENHAR POL'#205'GONO'
      TabOrder = 0
      OnClick = btDesenharPoligonoClick
    end
    object lbPoligonos: TListBox
      Left = 10
      Top = 40
      Width = 190
      Height = 80
      ItemHeight = 13
      TabOrder = 1
      OnClick = lbPoligonosClick
    end
    object lbPontos: TListBox
      Left = 10
      Top = 140
      Width = 190
      Height = 80
      ItemHeight = 13
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 772
    Top = 322
    Width = 210
    Height = 200
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 3
    DesignSize = (
      208
      198)
    object Label1: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'NAVEGAR/ZOOM PELO MUNDO'
      ExplicitWidth = 190
    end
    object Label2: TLabel
      Left = 36
      Top = 78
      Width = 50
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 'NAVEGAR'
    end
    object Label5: TLabel
      Left = 132
      Top = 78
      Width = 50
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = 'ZOOM'
    end
    object Label7: TLabel
      Left = 30
      Top = 43
      Width = 68
      Height = 12
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight, akBottom]
      AutoSize = False
      BiDiMode = bdLeftToRight
      Caption = 'Incremento'
      ParentBiDiMode = False
      ExplicitWidth = 70
      ExplicitHeight = 14
    end
    object btUp: TButton
      Left = 36
      Top = 96
      Width = 50
      Height = 25
      Caption = 'UP'
      TabOrder = 0
      OnClick = btUpClick
    end
    object btDown: TButton
      Left = 32
      Top = 150
      Width = 60
      Height = 25
      Caption = 'DOWN'
      TabOrder = 1
      OnClick = btDownClick
    end
    object btLeft: TButton
      Left = 10
      Top = 123
      Width = 50
      Height = 25
      Caption = 'LEFT'
      TabOrder = 2
      OnClick = btLeftClick
    end
    object btRight: TButton
      Left = 62
      Top = 123
      Width = 50
      Height = 25
      Caption = 'RIGHT'
      TabOrder = 3
      OnClick = btRightClick
    end
    object btIn: TButton
      Left = 132
      Top = 112
      Width = 50
      Height = 25
      Caption = 'IN'
      TabOrder = 4
      OnClick = btInClick
    end
    object btOut: TButton
      Left = 132
      Top = 140
      Width = 50
      Height = 25
      Caption = 'OUT'
      TabOrder = 5
      OnClick = btOutClick
    end
    object edIncremento: TEdit
      Left = 104
      Top = 40
      Width = 75
      Height = 19
      Alignment = taCenter
      TabOrder = 6
      Text = '25'
    end
  end
  object Panel4: TPanel
    Left = 772
    Top = 20
    Width = 210
    Height = 175
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 4
    DesignSize = (
      208
      173)
    object Label13: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'ALGORITMO DA RETA'
      ExplicitWidth = 190
    end
    object rgTipoReta: TRadioGroup
      Left = 10
      Top = 29
      Width = 190
      Height = 105
      ItemIndex = 0
      Items.Strings = (
        'LineTo'
        'DDA'
        'Bresenham')
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
    end
  end
  object btnRedesenhar: TButton
    Left = 782
    Top = 161
    Width = 190
    Height = 25
    Caption = 'REDESENHAR'
    TabOrder = 5
    OnClick = btnRedesenharClick
  end
  object Panel5: TPanel
    Left = 772
    Top = 215
    Width = 210
    Height = 85
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 6
    DesignSize = (
      208
      83)
    object Label14: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'CONTROLE DAS CIRCUNFER'#202'NCIAS'
      ExplicitWidth = 190
    end
    object btDesenharCirculo: TButton
      Left = 10
      Top = 37
      Width = 190
      Height = 38
      Caption = 'DESENHAR C'#205'RCULO'
      TabOrder = 0
      OnClick = btDesenharCirculoClick
    end
  end
  object Panel6: TPanel
    Left = 1002
    Top = 20
    Width = 210
    Height = 154
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 7
    DesignSize = (
      208
      152)
    object Label15: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'TRANSLA'#199#195'O'
      ExplicitWidth = 190
    end
    object Label16: TLabel
      Left = 10
      Top = 53
      Width = 76
      Height = 13
      Alignment = taCenter
      Caption = 'Deslocamento X'
    end
    object Label17: TLabel
      Left = 120
      Top = 53
      Width = 76
      Height = 13
      Alignment = taCenter
      Caption = 'Deslocamento Y'
    end
    object edDeslocamentoX: TEdit
      Left = 10
      Top = 69
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 0
      Text = '25'
    end
    object edDeslocamentoY: TEdit
      Left = 120
      Top = 69
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 1
      Text = '25'
    end
    object btTransladar: TButton
      Left = 10
      Top = 119
      Width = 190
      Height = 25
      Caption = 'TRANSLADAR'
      TabOrder = 2
      OnClick = btTransladarClick
    end
  end
  object Panel7: TPanel
    Left = 1002
    Top = 194
    Width = 210
    Height = 154
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 8
    DesignSize = (
      208
      152)
    object Label18: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'ESCALONAMENTO'
      ExplicitWidth = 190
    end
    object Label19: TLabel
      Left = 10
      Top = 36
      Width = 35
      Height = 13
      Alignment = taCenter
      Caption = 'Fator X'
    end
    object Label20: TLabel
      Left = 120
      Top = 36
      Width = 35
      Height = 13
      Alignment = taCenter
      Caption = 'Fator Y'
    end
    object edFatorX: TEdit
      Left = 10
      Top = 52
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 0
      Text = '2'
    end
    object edFatorY: TEdit
      Left = 120
      Top = 52
      Width = 80
      Height = 19
      Alignment = taCenter
      TabOrder = 1
      Text = '2'
    end
    object btEscalonar: TButton
      Left = 10
      Top = 119
      Width = 190
      Height = 25
      Caption = 'ESCALONAR'
      TabOrder = 2
      OnClick = btEscalonarClick
    end
    object cbEscalonamento: TCheckBox
      Left = 10
      Top = 86
      Width = 190
      Height = 17
      Caption = 'Usar coordenadas homog'#234'neas'
      TabOrder = 3
    end
  end
  object Panel8: TPanel
    Left = 1002
    Top = 368
    Width = 210
    Height = 154
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 9
    DesignSize = (
      208
      152)
    object Label21: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'ROTA'#199#195'O'
      ExplicitWidth = 190
    end
    object Label22: TLabel
      Left = 10
      Top = 36
      Width = 88
      Height = 13
      Alignment = taCenter
      Caption = #194'ngulo de rota'#231#227'o'
    end
    object edAngulo: TEdit
      Left = 10
      Top = 52
      Width = 190
      Height = 19
      Alignment = taCenter
      TabOrder = 0
      Text = '90'
    end
    object btRotacionar: TButton
      Left = 10
      Top = 119
      Width = 190
      Height = 25
      Caption = 'ROTACIONAR'
      TabOrder = 1
      OnClick = btRotacionarClick
    end
    object cbRotacao: TCheckBox
      Left = 10
      Top = 86
      Width = 190
      Height = 17
      Caption = 'Usar coordenadas homog'#234'neas'
      TabOrder = 2
    end
  end
  object Panel9: TPanel
    Left = 1232
    Top = 194
    Width = 210
    Height = 154
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 10
    DesignSize = (
      208
      152)
    object Label23: TLabel
      Left = 10
      Top = 11
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'REFLEX'#195'O'
    end
    object cbEixoX: TCheckBox
      Left = 10
      Top = 52
      Width = 190
      Height = 17
      Caption = 'Refletir no eixo X'
      TabOrder = 0
    end
    object cbEixoY: TCheckBox
      Left = 10
      Top = 75
      Width = 190
      Height = 17
      Caption = 'Refletir no eixo Y'
      TabOrder = 1
    end
    object btRefletir: TButton
      Left = 10
      Top = 119
      Width = 190
      Height = 25
      Caption = 'REFLETIR'
      TabOrder = 2
      OnClick = btRefletirClick
    end
  end
  object Panel10: TPanel
    Left = 1232
    Top = 20
    Width = 210
    Height = 154
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    ShowCaption = False
    TabOrder = 11
    DesignSize = (
      208
      152)
    object Label24: TLabel
      Left = 10
      Top = 10
      Width = 188
      Height = 13
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'PONTO CENTRAL'
      ExplicitWidth = 190
    end
    object Label25: TLabel
      Left = 10
      Top = 53
      Width = 68
      Height = 13
      Alignment = taCenter
      Caption = 'Coordenada X'
    end
    object Label26: TLabel
      Left = 120
      Top = 53
      Width = 68
      Height = 13
      Alignment = taCenter
      Caption = 'Coordenada Y'
    end
    object edXc: TEdit
      Left = 10
      Top = 72
      Width = 80
      Height = 19
      Alignment = taCenter
      Enabled = False
      ReadOnly = True
      TabOrder = 0
    end
    object edYc: TEdit
      Left = 120
      Top = 69
      Width = 80
      Height = 19
      Alignment = taCenter
      Enabled = False
      ReadOnly = True
      TabOrder = 1
    end
    object btPontoCentral: TButton
      Left = 10
      Top = 119
      Width = 190
      Height = 25
      Caption = 'PONTO CENTRAL'
      TabOrder = 2
      OnClick = btPontoCentralClick
    end
  end
end
