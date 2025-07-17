# Initialize passcraft package
from .password_generator import generate_password
from .passphrase_generator import generate_passphrase

__all__ = ['generate_password', 'generate_passphrase']