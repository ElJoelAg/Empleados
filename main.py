import socket
import asyncio
from telegram import Update
from telegram.ext import Application, CommandHandler, MessageHandler, filters, ContextTypes

token = "6915768523:AAFtRol_VxinGqkGE6TxRF2ppa4AX7iIEW8"
user_name = "RegisNotifyBot"  # Agrega el nombre de usuario aquí

class ListaEmpleados:
    def __init__(self):
        self.empleados = []

    def agregar_empleado(self, nombre, apellidos, numero_empleado, antiguedad):
        nuevo_empleado = {
            "nombre": nombre,
            "apellidos": apellidos,
            "numero_empleado": numero_empleado,
            "antiguedad": antiguedad
        }
        self.empleados.insert(0, nuevo_empleado)  # Insertar al principio de la lista
        return "Se ha guardado exitosamente:\n" + self.obtener_ultimo_empleado_como_string()

    def obtener_ultimo_empleado_como_string(self):
        if not self.empleados:
            return "Registro vacío"
        
        empleado = self.empleados[0]
        result = f"Nombre: {empleado['nombre']} {empleado['apellidos']}\n"
        result += f"Número de Empleado: {empleado['numero_empleado']}\n"
        result += f"Antigüedad: {empleado['antiguedad']} meses\n\n"
        return result

    def obtener_lista_como_string(self):
        if not self.empleados:
            return "Registro vacío"
        
        result = ""
        for empleado in self.empleados:
            result += f"Nombre: {empleado['nombre']} {empleado['apellidos']}\n"
            result += f"Número de Empleado: {empleado['numero_empleado']}\n"
            result += f"Antigüedad: {empleado['antiguedad']} meses\n\n"
        return result

    def quick_sort(self):
        def get_antiguedad(empleado):
            return int(empleado['antiguedad'])

        self.empleados.sort(key=get_antiguedad, reverse=True)

lista_empleados = ListaEmpleados()

async def start(update: Update, context: ContextTypes):
    await update.message.reply_text("Hola, ¿En qué puedo ayudarte?")
    context.user_data['espera_info'] = False

async def agregar(update: Update, context: ContextTypes):
    await update.message.reply_text("Ingresa la información en el siguiente orden:\n"
                                    "- Nombre\n"
                                    "- Apellido\n"
                                    "- Número de Empleado\n"
                                    "- Antigüedad (en meses)")
    context.user_data['espera_info'] = True

async def procesar_info(update: Update, context: ContextTypes):
    if context.user_data.get('espera_info', False):
        lines = update.message.text.strip().split('\n')
        if len(lines) == 4:
            nombre, apellidos, numero_empleado, antiguedad = lines
            respuesta = lista_empleados.agregar_empleado(nombre, apellidos, numero_empleado, antiguedad)
            await update.message.reply_text(respuesta)
            context.user_data['espera_info'] = False
        else:
            respuesta = "Error: Ingresa la información en el orden correcto."
            await update.message.reply_text(respuesta)

async def consultar(update: Update, context: ContextTypes):
    lista_empleados.quick_sort()
    mensaje = lista_empleados.obtener_lista_como_string()
    
    await update.message.reply_text(mensaje)

async def salir(update: Update, context: ContextTypes):
    await update.message.reply_text("Hasta luego :D")

async def error(update: Update, context: ContextTypes):
    await update.message.reply_text("Comando no reconocido :(")

if __name__ == "__main__":
    app = Application.builder().token(token).build()

    app.add_handler(CommandHandler("start", start))
    app.add_handler(CommandHandler("agregar", agregar))
    app.add_handler(MessageHandler(filters.TEXT & ~filters.COMMAND, procesar_info))
    app.add_handler(CommandHandler("consultar", consultar))
    app.add_handler(CommandHandler("salir", salir))

    app.add_handler(MessageHandler(filters.COMMAND & ~filters.ALL, error))

    asyncio.run(app.run_polling())