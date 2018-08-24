object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'UART CPP INTERFACE'
  ClientHeight = 415
  ClientWidth = 667
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 18
  object Label6: TLabel
    Left = 16
    Top = 8
    Width = 18
    Height = 18
    Caption = 'RX'
  end
  object Label7: TLabel
    Left = 16
    Top = 336
    Width = 19
    Height = 18
    Caption = 'TX'
  end
  object lblStatus: TLabel
    Left = 500
    Top = 318
    Width = 104
    Height = 18
    Caption = 'Desconectado'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object gbxSerial: TGroupBox
    Left = 452
    Top = 8
    Width = 207
    Height = 312
    Caption = 'Serial Port'
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 24
      Width = 34
      Height = 18
      Caption = 'Porta'
    end
    object Label2: TLabel
      Left = 32
      Top = 80
      Width = 68
      Height = 18
      Caption = 'Velocidade'
    end
    object Label3: TLabel
      Left = 32
      Top = 136
      Width = 72
      Height = 18
      Caption = 'Bits pacote'
    end
    object Label4: TLabel
      Left = 32
      Top = 196
      Width = 55
      Height = 18
      Caption = 'Paridade'
    end
    object Label5: TLabel
      Left = 28
      Top = 252
      Width = 66
      Height = 18
      Caption = 'Bit parada'
    end
    object cmbPorta: TComboBox
      Left = 32
      Top = 48
      Width = 145
      Height = 26
      Style = csOwnerDrawFixed
      ItemHeight = 20
      TabOrder = 0
    end
    object cmbVelocidade: TComboBox
      Left = 32
      Top = 104
      Width = 145
      Height = 26
      Style = csOwnerDrawFixed
      ItemHeight = 20
      ItemIndex = 0
      TabOrder = 1
      Text = '4800'
      Items.Strings = (
        '4800'
        '9600'
        '19200'
        '38400'
        '57600'
        '115200'
        '128000')
    end
    object cmbBitsDados: TComboBox
      Left = 32
      Top = 160
      Width = 145
      Height = 26
      Style = csOwnerDrawFixed
      ItemHeight = 20
      ItemIndex = 0
      TabOrder = 2
      Text = '8'
      Items.Strings = (
        '8'
        '9')
    end
    object cmbParidade: TComboBox
      Left = 32
      Top = 220
      Width = 145
      Height = 26
      Style = csOwnerDrawFixed
      ItemHeight = 20
      ItemIndex = 0
      TabOrder = 3
      Text = 'None'
      Items.Strings = (
        'None'
        'Even'
        'Odd'
        'Mark')
    end
    object cmbBitParada: TComboBox
      Left = 32
      Top = 275
      Width = 145
      Height = 26
      Style = csOwnerDrawFixed
      ItemHeight = 20
      ItemIndex = 0
      TabOrder = 4
      Text = '1'
      Items.Strings = (
        '1'
        '2')
    end
  end
  object mmoRx: TMemo
    Left = 8
    Top = 32
    Width = 438
    Height = 288
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btnLimparRx: TButton
    Left = 216
    Top = 1
    Width = 89
    Height = 25
    Caption = 'Limpar RX'
    TabOrder = 2
    OnClick = btnLimparRxClick
  end
  object btnListarPortas: TButton
    Left = 336
    Top = 1
    Width = 89
    Height = 25
    Caption = 'Listar Portas'
    TabOrder = 3
    OnClick = btnListarPortasClick
  end
  object edtTx: TEdit
    Left = 41
    Top = 333
    Width = 310
    Height = 26
    TabOrder = 4
  end
  object btnEnviar: TButton
    Left = 357
    Top = 334
    Width = 89
    Height = 25
    Caption = 'Enviar'
    TabOrder = 5
    OnClick = btnEnviarClick
  end
  object btnAbrirPorta: TButton
    Left = 484
    Top = 342
    Width = 145
    Height = 25
    Caption = 'Abrir porta'
    TabOrder = 6
    OnClick = btnAbrirPortaClick
  end
  object btnFecharPorta: TButton
    Left = 484
    Top = 373
    Width = 145
    Height = 25
    Caption = 'Fechar porta'
    TabOrder = 7
    OnClick = btnFecharPortaClick
  end
  object thread: TIdThreadComponent
    Active = False
    Loop = True
    Priority = tpHigher
    StopMode = smTerminate
    ThreadName = 'ctp_serial'
    OnRun = threadRun
    Left = 352
    Top = 40
  end
end
